#version 410
in vec4 vColor;
uniform vec4 lightColor;
uniform vec3 lightPosition;
uniform vec3 lightDirection;
uniform vec3 cameraPosition;
in vec4 vPosition;
out vec4 FragColor;
void main() 
{ 
	//ambient
	vec4 ambient = lightColor;
	
	//diffuse
	vec3 vertexNormal = normalize(vPosition.xyz);
	float lambert = dot(-lightDirection, vertexNormal);
	vec4 diffuse = vColor * lambert * lightColor;
	
	//specular
	float specularStrength = 5;
	vec3 viewDir = normalize(cameraPosition - vPosition.xyz);
	vec3 reflectDir = reflect(normalize(-lightDirection), vertexNormal);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), 128);
	//vec4 specular = specularStrength * spec * lightColor;
	vec4 specular = vec4(1, 1, 1, 1) * vColor * spec;
	
	FragColor = vColor * (ambient + diffuse + specular);
}

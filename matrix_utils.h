#define ANGLE 0.0

typedef float mat4[16];
typedef float vec3[3];
typedef float vec4[4];
GLfloat multi[16];
typedef float mat4x4[4][4];

void mat4_rotate_z(float angle,mat4 res);
void mat4_translate(vec3 move,mat4 res);
void mat4_multiply(mat4 a,mat4 b,mat4 res);
void mat4_identity(mat4 res);

void mat4_rotate_z(float angle,mat4 res)
{
angle=angle/180.0f*M_PI;

	res[0]=cos(angle);
	res[1]=sin(angle);
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=-sin(angle);
	res[5]=cos(angle);
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=0.0f;
	res[10]=1.0f;
	res[11]=0.0f;
	res[12]=0.0f;
	res[13]=0.0f;
	res[14]=0.0f;
	res[15]=1.0f;

}

void mat4_rotate_y(float angle,mat4 res)
{
angle=angle/180.0f*M_PI;

	res[0]=cos(angle);
	res[1]=0.0f;
	res[2]=-sin(angle);
	res[3]=0.0f;
	res[4]=0.0f;
	res[5]=1.0f;
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=sin(angle);
	res[9]=0.0f;
	res[10]=cos(angle);
	res[11]=0.0f;
	res[12]=0.0f;
	res[13]=0.0f;
	res[14]=0.0f;
	res[15]=1.0f;

}

void mat4_rotate_x(float angle,mat4 res)
{
angle=angle/180.0f*M_PI;

	res[0]=1.0f;
	res[1]=0.0f;
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=0.0f;
	res[5]=cos(angle);
	res[6]=sin(angle);
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=-sin(angle);
	res[10]=cos(angle);
	res[11]=0.0f;
	res[12]=0.0f;
	res[13]=0.0f;
	res[14]=0.0f;
	res[15]=1.0f;

}



void mat4_translate(vec3 move,mat4 res)
{	
	
	res[0]=1.0f;
	res[1]=0.0f;
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=0.0f;
	res[5]=1.0f;
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=0.0f;
	res[10]=1.0f;
	res[11]=0.0f;
	res[12]=move[0];
	res[13]=move[1];
	res[14]=move[2];
	res[15]=1.0f;
}


void mat4_multiply(mat4 a,mat4 b,mat4 res)
{
int i,j;
for(i=0;i<16;i=i+4){
	for(j=0;j<4;j++){
		res[i+j]=a[j]*b[i]+a[j+4]*b[i+1]+a[j+8]*b[i+2]+a[j+12]*b[i+3];
}
}
}


void mat4_identity(mat4 res){
	res[0]=1.0f;
	res[1]=0.0f;
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=0.0f;
	res[5]=1.0f;
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=0.0f;
	res[10]=1.0f;
	res[11]=0.0f;
	res[12]=0.0f;
	res[13]=0.0f;
	res[14]=0.0f;
	res[15]=1.0f;
}

void mat4_identity2(mat4 res){
	res[0]=1.0f;
	res[1]=0.0f;
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=0.0f;
	res[5]=1.0f;
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=0.0f;
	res[10]=1.0f;
	res[11]=0.0f;
	res[12]=0.5f;
	res[13]=0.5f;
	res[14]=0.0f;
	res[15]=1.0f;
}

void mat4_identity3(mat4 res){
	res[0]=cos(ANGLE);
	res[1]=sin(ANGLE);
	res[2]=0.0f;
	res[3]=0.0f;
	res[4]=-sin(ANGLE);
	res[5]=cos(ANGLE);
	res[6]=0.0f;
	res[7]=0.0f;
	res[8]=0.0f;
	res[9]=0.0f;
	res[10]=1.0f;
	res[11]=0.0f;
	res[12]=0.0f;
	res[13]=0.0f;
	res[14]=0.0f;
	res[15]=1.0f;
}



void vec3_subtract(vec3 v,vec3 a,vec3 b){
	v[0]=a[0]-b[0];
	v[1]=a[1]-b[1];
	v[2]=a[2]-b[2];
}

void vec3_cross_multiply(vec3 v,vec3 a,vec3 b){
	v[0]=a[1]*b[2]-a[2]*b[1];
	v[1]=a[2]*b[0]-a[0]*b[2];
	v[2]=a[0]*b[1]-a[1]*b[0];

}

void vec3_normalize(vec3 v){
	float p;

	p=0.0f;
	p+=v[0]*v[0];
	p+=v[1]*v[1];
	p+=v[2]*v[2];

	p=1.0f/(float)sqrt(p);

	v[0]*=p;
	v[1]*=p;
	v[2]*=p;
}
void mat4x4_perspective(float y_fov,float aspect,float n,float f,mat4 m)
{
float const a=1.f/(float)tan(y_fov/2.f);


m[0]=a/aspect;
m[1]=0.f;
m[2]=0.f;
m[3]=0.f;


m[4]=0.f;
m[5]=a;
m[6]=0.f;
m[7]=0.f;

m[8]=0.f;
m[9]=0.f;
m[10]=-((f+n)/(f-n));
m[11]=-1.f;

m[12]=0.f;
m[13]=0.f;
m[14]=-((2.0f*f*n)/(f-n));
m[15]=0.f;
}
/*
void mat4x4_perspective(float y_fov,float aspect,float n,float f,mat4x4 m)
{
float const a=1.f/(float)tan(y_fov/2.f);


m[0][0]=a/aspect;
m[0][1]=0.f;
m[0][2]=0.f;
m[0][3]=0.f;


m[1][0]=0.f;
m[1][1]=a;
m[1][2]=0.f;
m[1][3]=0.f;

m[2][0]=0.f;
m[2][1]=0.f;
m[2][2]=-((f+n)/(f-n));
m[2][3]=-1.f;

m[3][0]=0.f;
m[3][1]=0.f;
m[3][2]=-((2.0f*f*n)/(f-n));
m[3][3]=0.f;
}
*/
/*
void mat4_look_at(vec3 eye[0],vec3 eye[1],vec3 eye[2],vec3 center[0],vec3 center[1],vec3 center[2],vec3 up[0],up[1],up[2],mat4 m){

	vec3 f,s,t;

vec3_subtract(f,center,eye);
vec3_normalize(f);

vec3_cross_multiply(s,f,up);
vec3_normalize(s);

vec3_cross_multiply(t,s,f);

mat4 a;

m[0]=s[0];
m[1]=t[0];
m[2]=-f[0];
m[3]=0.0f;

m[4]=s[1];
m[5]=t[1];
m[6]=-f[1];
m[7]=0.0f;

m[8]=s[2];
m[9]=t[2];
m[10]=-f[2];
m[11]=0.0f;

m[12]=0.0f;
m[13]=0.0f;
m[14]=0.0f;
m[15]=1.0f;

eye[0]=-eye[0];
eye[1]=-eye[1];
eye[2]=-eye[2];

mat4_translate(eye,m);
}
*/
/*add 2/16*/

  void orthogonalMatrix(float left, float right,
                      float bottom, float top,
                      float near, float far,
                      GLfloat *matrix)
{
  float dx = right - left;
  float dy = top - bottom;
  float dz = far - near;

  matrix[ 0] =  2.0f / dx;
  matrix[ 5] =  2.0f / dy;
  matrix[10] = -2.0f / dz;
  matrix[12] = -(right + left) / dx;
  matrix[13] = -(top + bottom) / dy;
  matrix[14] = -(far + near) / dz;
  matrix[15] =  1.0f;
  matrix[ 1] = matrix[ 2] = matrix[ 3] = matrix[ 4] =
  matrix[ 6] = matrix[ 7] = matrix[ 8] = matrix[ 9] = matrix[11] = 0.0f;
}



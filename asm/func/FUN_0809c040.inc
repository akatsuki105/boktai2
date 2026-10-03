	ldr r0, _0809C058 @ =0x0300013C
	movs r2, #0
	str r2, [r0]
	ldr r0, _0809C05C @ =0x03002C14
	movs r1, #1
	strh r1, [r0]
	ldr r0, _0809C060 @ =0x03002C10
	strh r2, [r0]
	ldr r0, _0809C064 @ =0x03002C18
	strh r1, [r0]
	bx lr
	.align 2, 0
_0809C058: .4byte 0x0300013C
_0809C05C: .4byte 0x03002C14
_0809C060: .4byte 0x03002C10
_0809C064: .4byte 0x03002C18

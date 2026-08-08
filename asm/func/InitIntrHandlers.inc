	sub sp, #4
	ldr r0, _08229D40 @ =0x040000D4
	ldr r1, _08229D44 @ =gIntrTableTemplate
	str r1, [r0]
	ldr r1, _08229D48 @ =0x03002CB0
	str r1, [r0, #4]
	ldr r1, _08229D4C @ =0x8400000D
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08229D50 @ =IntrMain
	str r1, [r0]
	ldr r2, _08229D54 @ =IntrMain_Buffer
	str r2, [r0, #4]
	ldr r1, _08229D58 @ =0x84000200
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	ldr r1, _08229D5C @ =0x03007FFC
	str r2, [r1]
	ldr r1, _08229D60 @ =0x0300350C
	movs r2, #0
	str r2, [r1]
	ldr r1, _08229D64 @ =0x03002CE4
	str r2, [r1]
	str r2, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r1, _08229D68 @ =0x85006000
	str r1, [r0, #8]
	ldr r1, [r0, #8]
	movs r1, #0xa0
	str r1, [sp]
	mov r1, sp
	str r1, [r0]
	movs r1, #0xe0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	ldr r3, _08229D6C @ =0x85000100
	str r3, [r0, #8]
	ldr r1, [r0, #8]
	str r2, [sp]
	mov r2, sp
	str r2, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	str r1, [r0, #4]
	str r3, [r0, #8]
	ldr r0, [r0, #8]
	ldr r1, _08229D70 @ =0x04000200
	ldr r2, _08229D74 @ =0x00002001
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08229D78 @ =0x04000004
	movs r0, #8
	strh r0, [r1]
	ldr r1, _08229D7C @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	add sp, #4
	bx lr
	.align 2, 0
_08229D40: .4byte 0x040000D4
_08229D44: .4byte gIntrTableTemplate
_08229D48: .4byte 0x03002CB0
_08229D4C: .4byte 0x8400000D
_08229D50: .4byte IntrMain
_08229D54: .4byte IntrMain_Buffer
_08229D58: .4byte 0x84000200
_08229D5C: .4byte 0x03007FFC
_08229D60: .4byte 0x0300350C
_08229D64: .4byte 0x03002CE4
_08229D68: .4byte 0x85006000
_08229D6C: .4byte 0x85000100
_08229D70: .4byte 0x04000200
_08229D74: .4byte 0x00002001
_08229D78: .4byte 0x04000004
_08229D7C: .4byte 0x04000208

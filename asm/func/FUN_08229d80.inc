	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	movs r6, #0
	str r6, [sp, #4]
	ldr r1, _08229EDC @ =0x040000D4
	add r0, sp, #4
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r0, _08229EE0 @ =0x85006000
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xa0
	str r0, [sp, #4]
	add r5, sp, #4
	str r5, [r1]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	ldr r2, _08229EE4 @ =0x85000100
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	str r6, [sp, #4]
	str r5, [r1]
	movs r0, #0xa0
	lsls r0, r0, #0x13
	str r0, [r1, #4]
	str r2, [r1, #8]
	ldr r0, [r1, #8]
	ldr r4, _08229EE8 @ =0x04000208
	movs r0, #0
	mov sb, r0
	strh r6, [r4]
	ldr r2, _08229EEC @ =0x04000200
	ldrh r0, [r2]
	strh r6, [r2]
	ldr r0, _08229EF0 @ =0x0300350C
	movs r3, #1
	str r3, [r0]
	ldr r0, _08229EF4 @ =0x03000250
	str r6, [r0]
	ldr r0, _08229EF8 @ =0x0300351C
	movs r1, #1
	mov r8, r1
	strh r3, [r0]
	movs r0, #0x80
	lsls r0, r0, #6
	strh r0, [r2]
	ldrh r0, [r2]
	movs r5, #0x80
	lsls r5, r5, #5
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	mov r1, r8
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	ldr r2, _08229EFC @ =0x04000004
	movs r0, #8
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r2]
	ldrh r1, [r2]
	movs r0, #0xff
	ands r0, r1
	movs r5, #0x80
	lsls r5, r5, #7
	adds r1, r5, #0
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4]
	ldr r0, _08229F00 @ =0x04000132
	strh r6, [r0]
	ldr r0, _08229F04 @ =0x030044AC
	str r6, [r0]
	bl FUN_0822ecc0
	movs r0, #0
	bl FUN_0822b664
	movs r4, #0xb4
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xf0
	bl FUN_0822cdcc
	str r4, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0xf0
	bl FUN_0822cdcc
	movs r0, #0x3f
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_0822ce30
	ldr r0, _08229F08 @ =0x03003590
	strh r6, [r0]
	ldr r0, _08229F0C @ =0x03002CA8
	str r6, [r0]
	bl FUN_0822a2a8
	bl FUN_0822cf74
	bl FUN_0822f1b0
	bl FUN_0822ee38
	bl FUN_0822e7e4
	ldr r1, _08229F10 @ =FUN_0822db5c
	ldr r2, _08229F14 @ =FUN_0822aaac
	ldr r3, _08229F18 @ =FUN_0822f204
	movs r0, #0
	bl FUN_0822a448
	ldr r0, _08229F1C @ =0x03002CF0
	str r6, [r0]
	ldr r0, _08229F20 @ =0x03003504
	str r6, [r0]
	ldr r5, _08229F24 @ =0x03000258
	ldr r1, _08229F28 @ =VideoManager_Update
	adds r0, r5, #0
	movs r2, #0
	bl SetEntityRoutine
	ldr r4, _08229F2C @ =0x03000270
	ldr r1, _08229F30 @ =FUN_0822a228
	adds r0, r4, #0
	movs r2, #0
	bl SetEntityRoutine
	mov r0, sb
	strb r0, [r5, #0x14]
	mov r1, r8
	strb r1, [r5, #0x16]
	strh r6, [r5, #0x10]
	movs r0, #0xd
	strb r0, [r4, #0x14]
	strb r1, [r4, #0x16]
	strh r6, [r4, #0x10]
	adds r0, r5, #0
	bl AddEntity
	adds r0, r4, #0
	bl AddEntity
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08229EDC: .4byte 0x040000D4
_08229EE0: .4byte 0x85006000
_08229EE4: .4byte 0x85000100
_08229EE8: .4byte 0x04000208
_08229EEC: .4byte 0x04000200
_08229EF0: .4byte 0x0300350C
_08229EF4: .4byte 0x03000250
_08229EF8: .4byte 0x0300351C
_08229EFC: .4byte 0x04000004
_08229F00: .4byte 0x04000132
_08229F04: .4byte 0x030044AC
_08229F08: .4byte 0x03003590
_08229F0C: .4byte 0x03002CA8
_08229F10: .4byte FUN_0822db5c
_08229F14: .4byte FUN_0822aaac
_08229F18: .4byte FUN_0822f204
_08229F1C: .4byte 0x03002CF0
_08229F20: .4byte 0x03003504
_08229F24: .4byte 0x03000258
_08229F28: .4byte VideoManager_Update
_08229F2C: .4byte 0x03000270
_08229F30: .4byte FUN_0822a228

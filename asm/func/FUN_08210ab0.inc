	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	str r0, [sp, #0x14]
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #0
	bl FUN_0822b644
	ldr r0, _08210B98 @ =0x0000C091
	ldr r1, _08210B9C @ =0x00004F8F
	bl FUN_082310cc
	adds r2, r0, #0
	ldr r0, [sp, #0x14]
	str r2, [r0, #0x18]
	movs r4, #0
	str r4, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0822c0b8
	movs r0, #0
	movs r1, #3
	bl FUN_0822ba00
	str r4, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822c40c
	ldr r0, _08210BA0 @ =0x000092B3
	ldr r1, _08210BA4 @ =0x0000A41A
	bl FUN_082310cc
	adds r1, r0, #0
	adds r0, #0x14
	ldr r2, [sp, #0x14]
	str r0, [r2, #0x1c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _08210BA8 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	mov sb, r0
	ldr r0, [sp, #0x14]
	adds r0, #0x24
	ldrb r0, [r0]
	bl FUN_0820fedc
	str r0, [sp, #0x1c]
	movs r2, #0
	str r2, [sp, #0x18]
	ldr r7, _08210BAC @ =0x03003F60
	movs r6, #0
	mov r8, r6
	movs r0, #2
	mov sl, r0
_08210B3E:
	movs r5, #0
	movs r4, #0xe
_08210B42:
	movs r0, #0x10
	strh r0, [r7, #0x18]
	strh r6, [r7, #0x20]
	strh r6, [r7, #0x22]
	mov r2, sl
	str r2, [sp]
	str r2, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	mov r2, r8
	adds r2, #3
	movs r3, #2
	bl FUN_0822bdb8
	movs r0, #1
	add sb, r0
	ldr r2, [sp, #0x1c]
	cmp sb, r2
	bge _08210B88
	adds r4, #3
	adds r5, #1
	cmp r5, #4
	ble _08210B42
	movs r0, #3
	add r8, r0
	ldr r2, [sp, #0x18]
	adds r2, #1
	str r2, [sp, #0x18]
	cmp r2, #3
	ble _08210B3E
	ldr r0, [sp, #0x14]
	bl FUN_0821053c
_08210B88:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08210B98: .4byte 0x0000C091
_08210B9C: .4byte 0x00004F8F
_08210BA0: .4byte 0x000092B3
_08210BA4: .4byte 0x0000A41A
_08210BA8: .4byte 0x030043F0
_08210BAC: .4byte 0x03003F60

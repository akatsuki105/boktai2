	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r4, r0, #0
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #0
	bl FUN_0822b644
	ldr r0, _08211718 @ =0x0000C091
	ldr r1, _0821171C @ =0x00004F8F
	bl GetFile
	adds r2, r0, #0
	str r2, [r4, #0x18]
	movs r5, #0
	str r5, [sp]
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
	bl SetBGPrioDirect
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _08211720 @ =0x000092B3
	ldr r1, _08211724 @ =0x0000A41A
	bl GetFile
	adds r1, r0, #0
	adds r0, #0x14
	str r0, [r4, #0x1c]
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r1, _08211728 @ =0x030043F0
	movs r2, #0x30
	bl CpuSet
	movs r0, #0
	mov sb, r0
	adds r4, #0x24
	ldrb r0, [r4]
	bl FUN_08211154
	mov sl, r0
	movs r2, #0
	str r2, [sp, #0x14]
	ldr r7, _0821172C @ =0x03003F60
	movs r6, #0
	mov r8, r6
_082116C4:
	movs r5, #0
	movs r4, #3
_082116C8:
	movs r0, #0x10
	strh r0, [r7, #0x18]
	strh r6, [r7, #0x20]
	strh r6, [r7, #0x22]
	movs r0, #4
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	str r6, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0
	adds r1, r4, #0
	mov r2, r8
	adds r2, #3
	movs r3, #4
	bl FUN_0822bdb8
	movs r0, #1
	add sb, r0
	cmp sb, sl
	bge _08211708
	adds r4, #5
	adds r5, #1
	cmp r5, #4
	ble _082116C8
	movs r2, #5
	add r8, r2
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #1
	ble _082116C4
_08211708:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08211718: .4byte 0x0000C091
_0821171C: .4byte 0x00004F8F
_08211720: .4byte 0x000092B3
_08211724: .4byte 0x0000A41A
_08211728: .4byte 0x030043F0
_0821172C: .4byte 0x03003F60

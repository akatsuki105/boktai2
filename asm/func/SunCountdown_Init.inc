	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _0801100C @ =0x0300004C
	str r6, [r0]
	movs r4, #0
	strh r1, [r6, #0x18]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r6, #0x1a]
	ldr r0, _08011010 @ =0x0000596F
	strh r0, [r6, #0x1c]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r6, #0x1e]
	ldr r0, _08011014 @ =0x030043F0
	str r0, [r6, #0x20]
	strb r4, [r6, #0x1b]
	ldr r0, _08011018 @ =0x0000C091
	ldrh r1, [r6, #0x1c]
	bl GetFile
	adds r4, r0, #0
	cmp r4, #0
	beq _08011006
	ldr r0, _0801101C @ =0x000092B3
	ldrh r1, [r6, #0x1e]
	bl GetFile
	mov r8, r0
	cmp r0, #0
	bne _08011020
_08011006:
	movs r0, #1
	rsbs r0, r0, #0
	b _080110B6
	.align 2, 0
_0801100C: .4byte 0x0300004C
_08011010: .4byte 0x0000596F
_08011014: .4byte 0x030043F0
_08011018: .4byte 0x0000C091
_0801101C: .4byte 0x000092B3
_08011020:
	ldrb r0, [r4]
	cmp r0, #0x4d
	bne _08011036
	ldrb r0, [r4, #1]
	cmp r0, #0x50
	bne _08011036
	ldrb r0, [r6, #0x1b]
	movs r1, #0
	bl SetBGPrioDirect
	b _08011052
_08011036:
	movs r0, #0
	bl GetTilemapBuffer
	ldrb r2, [r6, #0x1b]
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	str r0, [sp, #0xc]
	adds r0, r2, #0
	adds r2, r4, #0
	movs r3, #0
	bl Video_SetupBG
_08011052:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl SunCountdown_GetTilePtr
	adds r2, r0, #0
	movs r4, #0
	ldr r0, _080110C4 @ =0x03003ED0
	mov ip, r0
	ldr r1, [r6, #0x20]
	mov sb, r1
_08011076:
	movs r3, #0
	mov r5, ip
	movs r7, #0x18
	ldrsh r0, [r5, r7]
	lsls r0, r0, #1
	adds r1, r4, #1
	cmp r3, r0
	bge _0801109E
	movs r0, #0xd0
	lsls r0, r0, #8
	adds r5, r0, #0
	ldr r4, _080110C4 @ =0x03003ED0
_0801108E:
	strh r5, [r2]
	adds r2, #2
	adds r3, #1
	movs r7, #0x18
	ldrsh r0, [r4, r7]
	lsls r0, r0, #1
	cmp r3, r0
	blt _0801108E
_0801109E:
	adds r4, r1, #0
	cmp r4, #0xe
	ble _08011076
	movs r0, #0xda
	lsls r0, r0, #1
	add r0, r8
	str r0, [r6, #0x24]
	ldr r2, _080110C8 @ =0x04000018
	mov r1, sb
	bl CpuSet
	movs r0, #0
_080110B6:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080110C4: .4byte 0x03003ED0
_080110C8: .4byte 0x04000018

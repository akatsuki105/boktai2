	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	adds r0, #0x58
	movs r1, #8
	bl ClearMemory
	ldr r0, _081D2874 @ =0x03002BE0
	mov r4, sp
	adds r2, r5, #0
	adds r2, #0xfc
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	adds r4, r5, #0
	adds r4, #0xb6
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D2860
	adds r0, r5, #0
	bl FUN_081d21d8
	movs r0, #0
	strb r0, [r4]
_081D2860:
	movs r2, #4
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081D2878
	movs r0, #1
	b _081D287A
	.align 2, 0
_081D2874: .4byte 0x03002BE0
_081D2878:
	movs r0, #0
_081D287A:
	cmp r0, #0
	beq _081D2880
	b _081D29F2
_081D2880:
	movs r1, #2
	ldrh r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081D288E
	movs r0, #1
	b _081D2890
_081D288E:
	movs r0, #0
_081D2890:
	mov sb, r0
	cmp r0, #0
	beq _081D2950
	adds r4, r5, #0
	adds r4, #0xfe
	adds r1, r5, #0
	adds r1, #0xba
	ldrh r0, [r1]
	ldrh r2, [r4]
	adds r0, r0, r2
	strh r0, [r4]
	ldrh r0, [r1]
	movs r1, #0x5a
	adds r1, r1, r5
	mov r8, r1
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	ble _081D28C0
	b _081D29F2
_081D28C0:
	strh r0, [r4]
	ldr r6, _081D293C @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D28F4
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	movs r0, #0
	mov r1, r8
	strh r0, [r1]
_081D28F4:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2940 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2944 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2948 @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D294C @ =0x00000159
	bl PlaySound_082406e0
	b _081D29F2
	.align 2, 0
_081D293C: .4byte 0x03002BE0
_081D2940: .4byte 0x00000261
_081D2944: .4byte 0x00000289
_081D2948: .4byte 0x0000028A
_081D294C: .4byte 0x00000159
_081D2950:
	adds r4, r5, #0
	adds r4, #0xfe
	adds r2, r5, #0
	adds r2, #0xba
	ldrh r0, [r4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2]
	rsbs r0, r0, #0
	movs r2, #0x5a
	adds r2, r2, r5
	mov r8, r2
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xcc
	movs r2, #0
	ldrsh r1, [r4, r2]
	ldr r0, [r0]
	cmp r0, r1
	blt _081D29F2
	strh r0, [r4]
	ldr r6, _081D2A00 @ =0x03002BE0
	ldr r0, [r6]
	movs r1, #1
	bl FUN_0807a954
	cmp r0, #0
	beq _081D29AE
	ldr r0, [r6]
	ldr r1, [r0, #0x2c]
	ldr r2, [r0, #0x30]
	str r1, [sp]
	str r2, [sp, #4]
	ldrh r2, [r4]
	mov r1, sp
	strh r2, [r1, #2]
	bl FUN_0807a91c
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r7]
	orrs r0, r1
	strh r0, [r7]
	mov r1, sb
	mov r0, r8
	strh r1, [r0]
_081D29AE:
	adds r0, r5, #0
	adds r0, #0xb2
	movs r1, #4
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xb6
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xd6
	ldrh r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _081D29F2
	movs r0, #0xac
	lsls r0, r0, #1
	bl sound_08240740
	ldr r0, _081D2A04 @ =0x00000261
	bl sound_08240740
	ldr r0, _081D2A08 @ =0x00000289
	bl sound_08240740
	ldr r0, _081D2A0C @ =0x0000028A
	bl sound_08240740
	movs r0, #0xa2
	lsls r0, r0, #2
	bl sound_08240740
	ldr r0, _081D2A10 @ =0x00000159
	bl PlaySound_082406e0
_081D29F2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D2A00: .4byte 0x03002BE0
_081D2A04: .4byte 0x00000261
_081D2A08: .4byte 0x00000289
_081D2A0C: .4byte 0x0000028A
_081D2A10: .4byte 0x00000159

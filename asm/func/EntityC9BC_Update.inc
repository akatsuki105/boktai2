	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _0800D8F0 @ =0x085B0A08
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D8F4
	asrs r0, r0, #0xc
	b _0800D8FA
	.align 2, 0
_0800D8F0: .4byte 0x085B0A08
_0800D8F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D8FA:
	strh r0, [r5, #0x20]
	adds r1, r5, #0
	adds r1, #0x22
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
	ldr r4, [r5, #0x74]
	movs r7, #0
	ldr r0, [r5, #0x1c]
	movs r1, #0x34
	adds r1, r1, r5
	mov r8, r1
	adds r2, r5, #0
	adds r2, #0x54
	str r2, [sp, #4]
	movs r1, #0x23
	adds r1, r1, r5
	mov sl, r1
	cmp r7, r0
	bhs _0800D976
	ldr r2, _0800D9B8 @ =0x085AA774
	mov sb, r2
_0800D926:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d46c
	ldrb r0, [r4, #3]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl _call_via_r3
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r7, #0
	bl FUN_0800d480
	adds r6, r4, #0
	adds r6, #0x44
	ldrb r0, [r6]
	cmp r0, #0
	beq _0800D968
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cb7c
	movs r0, #0
	strb r0, [r6]
_0800D968:
	adds r7, #1
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r4, r0
	ldr r0, [r5, #0x1c]
	cmp r7, r0
	blo _0800D926
_0800D976:
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x2c]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	movs r4, #5
	str r4, [sp]
	mov r0, r8
	bl rgb555_08237468
	ldr r1, [r5, #0x28]
	ldr r2, [r5, #0x30]
	movs r0, #0x24
	ldrsh r3, [r5, r0]
	str r4, [sp]
	ldr r0, [sp, #4]
	bl rgb555_08237468
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _0800D9BC
	ldrh r0, [r5, #0x24]
	adds r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1f
	ble _0800D9D0
	movs r0, #0x20
	strh r0, [r5, #0x24]
	movs r0, #1
	b _0800D9CE
	.align 2, 0
_0800D9B8: .4byte 0x085AA774
_0800D9BC:
	ldrh r0, [r5, #0x24]
	subs r0, #1
	strh r0, [r5, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D9D0
	movs r0, #0
	strh r0, [r5, #0x24]
	mov r1, sl
_0800D9CE:
	strb r0, [r1]
_0800D9D0:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

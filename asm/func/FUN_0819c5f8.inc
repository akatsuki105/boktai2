	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r4, [r5, #0x44]
	ldr r0, _0819C61C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C620
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C622
	.align 2, 0
_0819C61C: .4byte 0x0000046D
_0819C620:
	movs r0, #0
_0819C622:
	cmp r0, #0
	beq _0819C63C
	ldr r0, [r4]
	movs r1, #2
	orrs r0, r1
	str r0, [r4]
	ldr r0, _0819C650 @ =0x00000EAA
	adds r1, r6, r0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _0819C654 @ =0x000001E5
	bl PlaySound_082406e0
_0819C63C:
	ldr r1, _0819C658 @ =0x00000ECF
	adds r0, r6, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C660
	ldr r0, _0819C65C @ =0xFFFFFF00
	b _0819C66C
	.align 2, 0
_0819C650: .4byte 0x00000EAA
_0819C654: .4byte 0x000001E5
_0819C658: .4byte 0x00000ECF
_0819C65C: .4byte 0xFFFFFF00
_0819C660:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C66E
	movs r0, #0x80
	lsls r0, r0, #1
_0819C66C:
	adds r1, r1, r0
_0819C66E:
	cmp r1, #0
	bge _0819C684
	ldr r1, _0819C680 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r0, [r0]
	ldrb r1, [r4, #6]
	adds r0, r0, r1
	strb r0, [r4, #6]
	b _0819C690
	.align 2, 0
_0819C680: .4byte 0x00000EAA
_0819C684:
	ldr r1, _0819C6B4 @ =0x00000EAA
	adds r0, r6, r1
	ldrb r1, [r4, #6]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r4, #6]
_0819C690:
	adds r0, r7, #0
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _0819C6A6
	ldr r0, _0819C6B4 @ =0x00000EAA
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
_0819C6A6:
	ldrb r4, [r4, #6]
	cmp r4, #0x80
	ble _0819C6BC
	ldr r1, _0819C6B8 @ =0xFFFFFF00
	adds r4, r4, r1
	b _0819C6CA
	.align 2, 0
_0819C6B4: .4byte 0x00000EAA
_0819C6B8: .4byte 0xFFFFFF00
_0819C6BC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819C6CA
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r4, r0
_0819C6CA:
	adds r0, r5, #0
	bl FUN_0819ef24
	adds r0, r4, #0
	cmp r0, #0
	bge _0819C6D8
	rsbs r0, r0, #0
_0819C6D8:
	cmp r0, #0x60
	ble _0819C720
	ldr r4, _0819C728 @ =FUN_0819c740
	movs r3, #0x32
	ldr r0, _0819C72C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C730 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, _0819C734 @ =0x00000E48
	adds r2, r6, r0
	ldr r1, _0819C738 @ =0xFFFFFDFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0819C73C @ =0x00000EAE
	adds r1, r6, r0
	movs r0, #0x20
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_0819f530
_0819C720:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C728: .4byte FUN_0819c740
_0819C72C: .4byte 0x0000046D
_0819C730: .4byte 0x0000046B
_0819C734: .4byte 0x00000E48
_0819C738: .4byte 0xFFFFFDFF
_0819C73C: .4byte 0x00000EAE

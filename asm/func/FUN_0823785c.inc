	push {r4, lr}
	adds r2, r0, #0
	cmp r2, #0
	bne _08237874
	cmp r1, #0
	beq _0823787C
	cmp r1, #0
	ble _08237870
	movs r0, #0x40
	b _08237964
_08237870:
	movs r0, #0xc0
	b _08237964
_08237874:
	cmp r1, #0
	bne _08237884
	cmp r2, #0
	ble _08237880
_0823787C:
	movs r0, #0
	b _08237964
_08237880:
	movs r0, #0x80
	b _08237964
_08237884:
	cmp r2, #0
	ble _082378FC
	cmp r1, #0
	ble _082378BC
	cmp r2, r1
	ble _082378A4
	ldr r4, _082378A0 @ =0x085B0C88
	lsls r0, r1, #8
	adds r1, r2, #0
	bl Div
	adds r0, r0, r4
	ldrb r0, [r0]
	b _08237964
	.align 2, 0
_082378A0: .4byte 0x085B0C88
_082378A4:
	lsls r0, r2, #8
	bl Div
	ldr r1, _082378B8 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x40
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_082378B8: .4byte 0x085B0C88
_082378BC:
	rsbs r3, r1, #0
	cmp r2, r3
	ble _082378E4
	lsls r0, r1, #8
	rsbs r0, r0, #0
	adds r1, r2, #0
	bl Div
	ldr r1, _082378E0 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	b _08237964
	.align 2, 0
_082378E0: .4byte 0x085B0C88
_082378E4:
	lsls r0, r2, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _082378F8 @ =0x085B0C88
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #0xc0
	b _08237964
	.align 2, 0
_082378F8: .4byte 0x085B0C88
_082378FC:
	cmp r1, #0
	ble _08237934
	rsbs r3, r2, #0
	cmp r3, r1
	ble _08237920
	lsls r0, r1, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _0823791C @ =0x085B0C88
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x80
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_0823791C: .4byte 0x085B0C88
_08237920:
	lsls r0, r2, #8
	bl Div
	ldr r1, _08237930 @ =0x085B0C88
	subs r1, r1, r0
	ldrb r0, [r1]
	adds r0, #0x40
	b _08237964
	.align 2, 0
_08237930: .4byte 0x085B0C88
_08237934:
	rsbs r4, r2, #0
	rsbs r3, r1, #0
	cmp r4, r3
	bgt _08237954
	lsls r0, r2, #8
	adds r1, r3, #0
	bl Div
	ldr r1, _08237950 @ =0x085B0C88
	subs r1, r1, r0
	ldrb r1, [r1]
	movs r0, #0xc0
	subs r0, r0, r1
	b _08237964
	.align 2, 0
_08237950: .4byte 0x085B0C88
_08237954:
	lsls r0, r1, #8
	adds r1, r4, #0
	bl Div
	ldr r1, _0823796C @ =0x085B0C88
	subs r1, r1, r0
	ldrb r0, [r1]
	adds r0, #0x80
_08237964:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0823796C: .4byte 0x085B0C88

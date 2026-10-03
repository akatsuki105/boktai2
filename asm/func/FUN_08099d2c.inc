	push {lr}
	adds r2, r0, #0
	ldr r0, _08099D5C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08099D88
	ldr r0, _08099D60 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08099D6E
	ldr r3, _08099D64 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #1
	bls _08099D68
	movs r0, #0
	strb r0, [r1]
	b _08099D7E
	.align 2, 0
_08099D5C: .4byte 0x030044E0
_08099D60: .4byte 0x0000400D
_08099D64: .4byte 0x0000400E
_08099D68:
	adds r0, #1
	strb r0, [r1]
	b _08099D7E
_08099D6E:
	ldr r3, _08099D84 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r1, #1
	subs r1, r1, r2
	strb r1, [r0]
_08099D7E:
	movs r0, #0xcd
	lsls r0, r0, #1
	b _08099E1E
	.align 2, 0
_08099D84: .4byte 0x0000400E
_08099D88:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08099DD8
	ldr r0, _08099DB0 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #1
	bhi _08099DBE
	ldr r3, _08099DB4 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _08099DB8
	movs r0, #2
	strb r0, [r1]
	b _08099DCE
	.align 2, 0
_08099DB0: .4byte 0x0000400D
_08099DB4: .4byte 0x0000400E
_08099DB8:
	subs r0, #1
	strb r0, [r1]
	b _08099DCE
_08099DBE:
	ldr r3, _08099DD4 @ =0x0000400E
	adds r0, r2, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r2, [r0]
	movs r1, #1
	subs r1, r1, r2
	strb r1, [r0]
_08099DCE:
	movs r0, #0xcd
	lsls r0, r0, #1
	b _08099E1E
	.align 2, 0
_08099DD4: .4byte 0x0000400E
_08099DD8:
	movs r0, #0x40
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08099DFC
	ldr r0, _08099DF4 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _08099DF8
	movs r0, #2
	b _08099E1A
	.align 2, 0
_08099DF4: .4byte 0x0000400D
_08099DF8:
	subs r0, #1
	b _08099E1A
_08099DFC:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08099E26
	ldr r0, _08099E14 @ =0x0000400D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #2
	bne _08099E18
	strb r3, [r1]
	b _08099E1C
	.align 2, 0
_08099E14: .4byte 0x0000400D
_08099E18:
	adds r0, #1
_08099E1A:
	strb r0, [r1]
_08099E1C:
	movs r0, #0xdc
_08099E1E:
	bl PlaySound_082406e0
	movs r0, #1
	b _08099E28
_08099E26:
	movs r0, #0
_08099E28:
	pop {r1}
	bx r1

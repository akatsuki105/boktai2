	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r1, _081DB008 @ =0x0000032D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DB020
	cmp r0, #1
	bgt _081DB00C
	cmp r0, #0
	beq _081DB012
	b _081DB03C
	.align 2, 0
_081DB008: .4byte 0x0000032D
_081DB00C:
	cmp r0, #2
	beq _081DB030
	b _081DB03C
_081DB012:
	ldr r1, _081DB01C @ =0x00000322
	adds r0, r5, r1
	ldrb r1, [r0]
	b _081DB03E
	.align 2, 0
_081DB01C: .4byte 0x00000322
_081DB020:
	ldr r1, _081DB02C @ =0x00000323
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #2
	b _081DB03E
	.align 2, 0
_081DB02C: .4byte 0x00000323
_081DB030:
	movs r1, #0xc9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r1, r0, #5
	b _081DB03E
_081DB03C:
	movs r1, #0
_081DB03E:
	ldr r0, _081DB070 @ =0x0000032B
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	adds r4, r1, #0
	adds r4, #9
	cmp r0, r4
	beq _081DB06A
	bl FUN_08049e5c
	movs r1, #0xc3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, r0, r4
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r4, [r6]
_081DB06A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DB070: .4byte 0x0000032B

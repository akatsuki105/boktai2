	push {r4, r5, lr}
	ldr r4, [r0, #0x1c]
	movs r5, #0
	b _08048CBA
_08048C60:
	lsls r0, r0, #0x18
	cmp r0, #0
	blt _08048CAE
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bne _08048C7E
_08048C6C:
	adds r4, #1
	ldrb r0, [r4]
	cmp r0, #0x3e
	beq _08048CAA
	cmp r0, #0
	beq _08048CAA
	cmp r0, #0xa
	bne _08048C6C
	b _08048CAA
_08048C7E:
	cmp r0, #0x1f
	bne _08048CA8
	adds r0, r4, #0
	bl FUN_08048afc
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _08048CA4 @ =0x0000FFFF
	cmp r2, r0
	beq _08048CA8
	movs r0, #0xff
	lsls r0, r0, #8
	adds r1, r0, #0
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08048CAE
	adds r5, #1
	b _08048CB0
	.align 2, 0
_08048CA4: .4byte 0x0000FFFF
_08048CA8:
	adds r5, #1
_08048CAA:
	adds r4, #1
	b _08048CB2
_08048CAE:
	adds r5, #2
_08048CB0:
	adds r4, #2
_08048CB2:
	cmp r5, #0xfe
	ble _08048CBA
	movs r5, #0xff
	b _08048CC0
_08048CBA:
	ldrb r0, [r4]
	cmp r0, #0
	bne _08048C60
_08048CC0:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1

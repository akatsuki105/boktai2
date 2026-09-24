	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D80A6:
	adds r0, r7, #0
	adds r0, #0xa0
	movs r1, #1
	lsls r1, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D80BA
	movs r0, #1
	b _081D80BC
_081D80BA:
	movs r0, #0
_081D80BC:
	cmp r0, #0
	beq _081D8122
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x20
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D80EC
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D80EC:
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D8102
	movs r0, #1
	b _081D8104
_081D8102:
	movs r0, #0
_081D8104:
	cmp r0, #0
	beq _081D811C
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D811C:
	adds r0, r5, #0
	bl Free
_081D8122:
	adds r6, #1
	cmp r6, #0x1f
	ble _081D80A6
	ldr r1, _081D8134 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8134: .4byte 0x0300019C

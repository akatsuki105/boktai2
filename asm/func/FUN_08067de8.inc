	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08067E00 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08067E9C
	cmp r0, #1
	bgt _08067E04
	cmp r0, #0
	beq _08067E0C
	b _08067F50
	.align 2, 0
_08067E00: .4byte 0x0000037D
_08067E04:
	cmp r0, #2
	bne _08067E0A
	b _08067F20
_08067E0A:
	b _08067F50
_08067E0C:
	ldr r2, _08067E38 @ =0x000003BD
	adds r0, r4, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08067E3C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08067E40
	asrs r0, r0, #0xc
	b _08067E46
	.align 2, 0
_08067E38: .4byte 0x000003BD
_08067E3C: .4byte 0x085B0A08
_08067E40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067E46:
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #2
	cmp r0, #0
	blt _08067E5A
	asrs r0, r0, #0xc
	b _08067E60
_08067E5A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08067E60:
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #6
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08067E98 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bls _08067F50
	adds r0, r4, #0
	movs r1, #5
	movs r2, #1
	bl FUN_08060b84
	b _08067F50
	.align 2, 0
_08067E98: .4byte 0x0000037E
_08067E9C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #6
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08067EFC @ =0x000003BD
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r1, r0
	bne _08067F14
	adds r0, r4, #0
	adds r0, #0x2c
	subs r2, #0xd5
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08003f24
	cmp r0, #0
	ble _08067F14
	ldr r1, _08067F00 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08067EF2
	ldr r2, _08067F04 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #2
	bne _08067EF2
	movs r1, #1
_08067EF2:
	cmp r1, #0
	beq _08067F08
	adds r0, r4, #0
	movs r1, #0
	b _08067F0C
	.align 2, 0
_08067EFC: .4byte 0x000003BD
_08067F00: .4byte 0x00000446
_08067F04: .4byte 0x00000442
_08067F08:
	adds r0, r4, #0
	movs r1, #5
_08067F0C:
	movs r2, #0
	bl FUN_08060b84
	b _08067F50
_08067F14:
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	bl FUN_08060b84
	b _08067F50
_08067F20:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #7
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _08067F50
	adds r0, r4, #0
	movs r1, #4
	movs r2, #1
	bl FUN_08060b84
	movs r2, #0xef
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08067F50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

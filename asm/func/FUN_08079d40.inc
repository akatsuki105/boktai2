	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x24
	adds r0, r4, #0
	bl FUN_0823b4b8
	adds r0, r4, #0
	bl FUN_080417dc
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _08079DA4 @ =0x000004BC
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r2, _08079DA8 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DAC
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _08079DB8
	.align 2, 0
_08079DA4: .4byte 0x000004BC
_08079DA8: .4byte 0x000003F6
_08079DAC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_08079DB8:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DD4
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08079DDE
_08079DD4:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08079DDE:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08060c50
	cmp r0, #0
	beq _08079DFC
	ldr r1, _08079DF8 @ =0x0000060C
	adds r0, r5, r1
	bl FUN_080136b4
	b _08079E04
	.align 2, 0
_08079DF8: .4byte 0x0000060C
_08079DFC:
	ldr r2, _08079E20 @ =0x0000060C
	adds r0, r5, r2
	bl FUN_08013698
_08079E04:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08060c50
	cmp r0, #0
	beq _08079E24
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _08079E42
	.align 2, 0
_08079E20: .4byte 0x0000060C
_08079E24:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08079E48 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_08079E42:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08079E48: .4byte 0x0000FFFB

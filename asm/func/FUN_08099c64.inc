	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _08099C80
	ldr r1, _08099C7C @ =0x0000144C
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r3, #0x4f
	b _08099CA4
	.align 2, 0
_08099C7C: .4byte 0x0000144C
_08099C80:
	ldr r3, _08099CAC @ =0x0000144C
	adds r2, r5, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _08099CB0 @ =0x0000400D
	adds r2, r5, r0
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r3, #0x1a
	adds r1, r5, r3
	strh r0, [r1]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08099CB4
	movs r3, #0x57
_08099CA4:
	movs r6, #0x52
	movs r7, #0x55
	b _08099CC6
	.align 2, 0
_08099CAC: .4byte 0x0000144C
_08099CB0: .4byte 0x0000400D
_08099CB4:
	cmp r0, #1
	bne _08099CC0
	movs r3, #0x4f
	movs r6, #0x5a
	movs r7, #0x55
	b _08099CC6
_08099CC0:
	movs r3, #0x4f
	movs r6, #0x52
	movs r7, #0x5d
_08099CC6:
	ldr r1, _08099D14 @ =0x00001CE4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	ldr r2, _08099D18 @ =0x0000400E
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, r2, r3
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r3, _08099D1C @ =0x00001D44
	adds r0, r5, r3
	ldr r2, _08099D20 @ =0x0000400F
	adds r1, r5, r2
	ldrb r2, [r1]
	adds r2, r2, r6
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r3, _08099D24 @ =0x00001DA4
	adds r0, r5, r3
	adds r2, r7, #1
	ldr r3, _08099D28 @ =0x00004010
	adds r1, r5, r3
	ldrb r1, [r1]
	subs r2, r2, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl MainSprite_SetPose
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08099D14: .4byte 0x00001CE4
_08099D18: .4byte 0x0000400E
_08099D1C: .4byte 0x00001D44
_08099D20: .4byte 0x0000400F
_08099D24: .4byte 0x00001DA4
_08099D28: .4byte 0x00004010

	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0806801E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08060b84
	ldr r2, _08068034 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0806801E:
	ldr r1, _08068038 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _0806802A
	b _080682D2
_0806802A:
	lsls r0, r0, #2
	ldr r1, _0806803C @ =_08068040
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08068034: .4byte 0x00000951
_08068038: .4byte 0x0000037D
_0806803C: .4byte _08068040
_08068040: @ jump table
	.4byte _08068054 @ case 0
	.4byte _08068078 @ case 1
	.4byte _0806814C @ case 2
	.4byte _08068210 @ case 3
	.4byte _0806828C @ case 4
_08068054:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08060b84
	b _080682D2
_08068078:
	ldr r1, _080680A4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _080680CE
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080680B0
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080680A8 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080680AC @ =0x000002E7
	b _080680BA
	.align 2, 0
_080680A4: .4byte 0x0000037E
_080680A8: .4byte 0x000002E6
_080680AC: .4byte 0x000002E7
_080680B0:
	strb r2, [r1]
	ldr r1, _08068130 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080680BA:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08067f88
	ldr r2, _08068134 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080680CE:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _080680F6
	b _080682D2
_080680F6:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068110
	b _0806824C
_08068110:
	adds r0, r4, #0
	bl FUN_08067f58
	adds r1, r0, #0
	cmp r1, #0
	beq _08068140
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r0, _08068138 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0806813C @ =0x00000404
	adds r1, r4, r2
	b _08068274
	.align 2, 0
_08068130: .4byte 0x000002E6
_08068134: .4byte 0x0000037E
_08068138: .4byte 0x00000409
_0806813C: .4byte 0x00000404
_08068140:
	ldr r2, _08068148 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080681FE
	.align 2, 0
_08068148: .4byte 0x00000404
_0806814C:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _08068180 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _0806818C
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _0806818C
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _08068184
	movs r0, #0xc2
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _0806818C
	.align 2, 0
_08068180: .4byte 0x00000404
_08068184:
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0806818C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r5, #0
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08067f88
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_08061f6c
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080681E8
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _080681E4 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _0806824C
	.align 2, 0
_080681E4: .4byte 0x00000409
_080681E8:
	adds r0, r4, #0
	bl FUN_08067f58
	cmp r0, #0
	bne _080682D2
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _0806820C @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080681FE:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08060b84
	b _080682D2
	.align 2, 0
_0806820C: .4byte 0x00000409
_08068210:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08068258
_0806824C:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08060b84
	b _080682D2
_08068258:
	adds r0, r4, #0
	bl FUN_08067f58
	cmp r0, #0
	beq _080682D2
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08068284 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08068288 @ =0x00000404
	adds r1, r4, r0
_08068274:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08060b84
	b _080682D2
	.align 2, 0
_08068284: .4byte 0x00000409
_08068288: .4byte 0x00000404
_0806828C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080682D2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080682D8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08060b84
_080682D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080682D8: .4byte 0x000002E7

	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080744E0 @ =0x00000951
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0]
	ldr r1, _080744E4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080744D4
	b _080746E4
_080744D4:
	lsls r0, r0, #2
	ldr r1, _080744E8 @ =_080744EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080744E0: .4byte 0x00000951
_080744E4: .4byte 0x0000037D
_080744E8: .4byte _080744EC
_080744EC: @ jump table
	.4byte _0807450C @ case 0
	.4byte _0807453C @ case 1
	.4byte _0807458C @ case 2
	.4byte _080745E0 @ case 3
	.4byte _08074620 @ case 4
	.4byte _0807463A @ case 5
	.4byte _08074680 @ case 6
	.4byte _080746BC @ case 7
_0807450C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	bne _0807452A
	b _080746E4
_0807452A:
	ldr r0, _08074538 @ =0x000001F7
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	b _08074610
	.align 2, 0
_08074538: .4byte 0x000001F7
_0807453C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _08074584 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08074568
	b _080746E4
_08074568:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08060b84
	ldr r1, _08074588 @ =0x000004A7
	adds r0, r4, r1
	ldrb r2, [r0]
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080c1abc
	b _080746E4
	.align 2, 0
_08074584: .4byte 0x0000037E
_08074588: .4byte 0x000004A7
_0807458C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080745D8 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #6
	bne _080745B4
	ldr r0, _080745DC @ =0x00000277
	bl PlaySound_082406e0
_080745B4:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080745C4
	b _080746E4
_080745C4:
	movs r0, #0x9e
	lsls r0, r0, #2
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	bl FUN_08060b84
	b _080746E4
	.align 2, 0
_080745D8: .4byte 0x0000037E
_080745DC: .4byte 0x00000277
_080745E0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _0807461C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080746E4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
_08074610:
	bl FUN_08060b84
	adds r0, r4, #0
	bl FUN_080726b4
	b _080746E4
	.align 2, 0
_0807461C: .4byte 0x0000037E
_08074620:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	b _080746E4
_0807463A:
	ldr r0, _0807467C @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _08074652
	movs r0, #0xfb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_08074652:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080746E4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl FUN_08060b84
	b _080746E4
	.align 2, 0
_0807467C: .4byte 0x0000037E
_08074680:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r0, _080746B8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080746E4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08060b84
	b _080746E4
	.align 2, 0
_080746B8: .4byte 0x0000037E
_080746BC:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _080746E4
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_080746E4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

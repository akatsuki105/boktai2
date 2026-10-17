	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _080D686C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6828
	ldr r3, _080D6870 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6828
	movs r1, #1
_080D6828:
	cmp r1, #0
	bne _080D6848
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6848
	adds r0, r5, #0
	bl FUN_080ced90
	adds r4, r0, #0
_080D6848:
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D6878
	ldr r3, _080D6874 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x18
	cmp r0, #0
	beq _080D6862
	movs r4, #0x19
_080D6862:
	adds r0, r5, #0
	bl FUN_08078548
	b _080D69D4
	.align 2, 0
_080D686C: .4byte 0x00000446
_080D6870: .4byte 0x00000442
_080D6874: .4byte 0x000003D2
_080D6878:
	adds r0, r4, #0
	subs r0, #0x18
	cmp r0, #1
	bls _080D68A2
	cmp r4, #0x16
	beq _080D68A2
	cmp r4, #0x17
	beq _080D68A2
	cmp r4, #0x15
	beq _080D68A2
	cmp r4, #0x14
	beq _080D68A2
	cmp r4, #0x13
	beq _080D68A2
	movs r1, #0xfb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D68A2
	movs r4, #0x12
_080D68A2:
	subs r0, r4, #2
	cmp r0, #0x1e
	bhi _080D6942
	lsls r0, r0, #2
	ldr r1, _080D68B4 @ =_080D68B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D68B4: .4byte _080D68B8
_080D68B8: @ jump table
	.4byte _080D69D4 @ case 0
	.4byte _080D69D4 @ case 1
	.4byte _080D6934 @ case 2
	.4byte _080D693E @ case 3
	.4byte _080D693E @ case 4
	.4byte _080D69D4 @ case 5
	.4byte _080D693E @ case 6
	.4byte _080D693E @ case 7
	.4byte _080D693E @ case 8
	.4byte _080D693E @ case 9
	.4byte _080D693E @ case 10
	.4byte _080D69D4 @ case 11
	.4byte _080D693E @ case 12
	.4byte _080D69D4 @ case 13
	.4byte _080D693E @ case 14
	.4byte _080D69D4 @ case 15
	.4byte _080D693E @ case 16
	.4byte _080D693E @ case 17
	.4byte _080D693E @ case 18
	.4byte _080D693E @ case 19
	.4byte _080D69D4 @ case 20
	.4byte _080D69D4 @ case 21
	.4byte _080D69D4 @ case 22
	.4byte _080D69D4 @ case 23
	.4byte _080D6942 @ case 24
	.4byte _080D6942 @ case 25
	.4byte _080D6942 @ case 26
	.4byte _080D6942 @ case 27
	.4byte _080D6942 @ case 28
	.4byte _080D6942 @ case 29
	.4byte _080D693E @ case 30
_080D6934:
	adds r0, r5, #0
	bl FUN_080d664c
	cmp r0, #0
	bne _080D69D4
_080D693E:
	movs r4, #0
	b _080D69D4
_080D6942:
	ldr r2, _080D697C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D695A
	ldr r3, _080D6980 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D695A
	movs r1, #1
_080D695A:
	cmp r1, #0
	beq _080D6984
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	b _080D69C8
	.align 2, 0
_080D697C: .4byte 0x00000446
_080D6980: .4byte 0x00000442
_080D6984:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D699A
	movs r4, #3
	b _080D69D4
_080D699A:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D69B4
	adds r0, r5, #0
	adds r0, #0x24
	bl MapItemManager_TryOpen
	lsls r0, r0, #0x18
	movs r4, #7
	cmp r0, #0
	beq _080D69D4
	b _080D693E
_080D69B4:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	ldrh r1, [r2]
_080D69C8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D693E
	movs r4, #1
_080D69D4:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

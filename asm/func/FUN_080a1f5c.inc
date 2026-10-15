	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080865c0
	adds r3, r0, #0
	cmp r3, #0
	beq _080A1FA2
	movs r2, #0
	ldrsh r1, [r3, r2]
	adds r2, r5, #0
	adds r2, #0xac
	movs r4, #0
	ldrsh r2, [r2, r4]
	subs r1, r1, r2
	cmp r1, #0
	bge _080A1F7E
	rsbs r1, r1, #0
_080A1F7E:
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r1, #4
	ldrsh r2, [r3, r1]
	adds r1, r5, #0
	adds r1, #0xb0
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r1, r2, r1
	cmp r1, #0
	bge _080A1F96
	rsbs r1, r1, #0
_080A1F96:
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r4, #0x7f
	bhi _080A1FA2
	cmp r2, #0x7f
	bls _080A1FA6
_080A1FA2:
	movs r0, #0
	b _080A1FBA
_080A1FA6:
	adds r1, r4, #0
	muls r1, r4, r1
	adds r4, r2, #0
	muls r4, r2, r4
	adds r2, r4, #0
	adds r1, r1, r2
	ldr r2, _080A1FC0 @ =0x00003FFF
	cmp r1, r2
	bgt _080A1FBA
	movs r0, #1
_080A1FBA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080A1FC0: .4byte 0x00003FFF

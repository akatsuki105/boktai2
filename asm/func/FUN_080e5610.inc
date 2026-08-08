	push {r4, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	subs r0, #1
	cmp r0, #0x1d
	bhi _080E5712
	lsls r0, r0, #2
	ldr r1, _080E562C @ =_080E5630
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E562C: .4byte _080E5630
_080E5630: @ jump table
	.4byte _080E56B4 @ case 0
	.4byte _080E5712 @ case 1
	.4byte _080E56C0 @ case 2
	.4byte _080E56A8 @ case 3
	.4byte _080E56E4 @ case 4
	.4byte _080E56E4 @ case 5
	.4byte _080E56E4 @ case 6
	.4byte _080E56E4 @ case 7
	.4byte _080E5712 @ case 8
	.4byte _080E56CC @ case 9
	.4byte _080E56D8 @ case 10
	.4byte _080E5712 @ case 11
	.4byte _080E5712 @ case 12
	.4byte _080E5712 @ case 13
	.4byte _080E5712 @ case 14
	.4byte _080E5712 @ case 15
	.4byte _080E5712 @ case 16
	.4byte _080E5712 @ case 17
	.4byte _080E5712 @ case 18
	.4byte _080E5712 @ case 19
	.4byte _080E56F0 @ case 20
	.4byte _080E5712 @ case 21
	.4byte _080E56FC @ case 22
	.4byte _080E5712 @ case 23
	.4byte _080E5712 @ case 24
	.4byte _080E5712 @ case 25
	.4byte _080E5708 @ case 26
	.4byte _080E56A8 @ case 27
	.4byte _080E5712 @ case 28
	.4byte _080E56C0 @ case 29
_080E56A8:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e53a8
	b _080E5712
_080E56B4:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e53ec
	b _080E5712
_080E56C0:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e54c8
	b _080E5712
_080E56CC:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e5508
	b _080E5712
_080E56D8:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e5590
	b _080E5712
_080E56E4:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e5438
	b _080E5712
_080E56F0:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e554c
	b _080E5712
_080E56FC:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e55d0
	b _080E5712
_080E5708:
	adds r0, r2, #0
	adds r1, r4, #0
	adds r2, r3, #0
	bl FUN_080e547c
_080E5712:
	pop {r4}
	pop {r0}
	bx r0

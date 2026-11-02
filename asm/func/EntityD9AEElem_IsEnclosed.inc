	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
_08003274:
	adds r0, r5, #0
	adds r0, #0xba
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r2, r4, #0
	bl EntityD9AEElem_IsSideBlocked
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800328A
	adds r6, #1
_0800328A:
	adds r4, #1
	cmp r4, #3
	ble _08003274
	cmp r6, #2
	bgt _08003298
	movs r0, #0
	b _0800329A
_08003298:
	movs r0, #1
_0800329A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

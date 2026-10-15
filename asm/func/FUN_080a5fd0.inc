	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x9a
	ldrh r0, [r4]
	cmp r0, #0
	bne _080A5FE6
	movs r0, #0xa5
	lsls r0, r0, #2
	bl PlaySound_082406e0
_080A5FE6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080A6000
	adds r0, r5, #0
	bl FUN_080a5ea4
	adds r0, r5, #0
	bl KillEntity
_080A6000:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

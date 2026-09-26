	push {lr}
	adds r2, r0, #0
	adds r0, #0x96
	ldrh r0, [r0]
	lsls r1, r0, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #7
	bhi _080AB9B0
	lsrs r1, r1, #0x12
	b _080AB9B4
_080AB9B0:
	lsrs r0, r1, #0x12
	adds r1, r0, #4
_080AB9B4:
	adds r0, r2, #0
	adds r0, #0x48
	strh r1, [r0, #0x10]
	adds r1, r2, #0
	adds r1, #0x96
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x17
	bls _080AB9DC
	ldr r0, [r2, #0x48]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #0x48]
	adds r1, r2, #0
	adds r1, #0x90
	movs r0, #0
	strb r0, [r1]
_080AB9DC:
	pop {r0}
	bx r0

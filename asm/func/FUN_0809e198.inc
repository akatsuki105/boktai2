	push {r4, r5, r6, lr}
	mov ip, r0
	adds r6, r2, #0
	cmp r3, #0
	beq _0809E1B8
	ldr r0, _0809E1B0 @ =0x085AD004
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1B4 @ =0x085AD00C
	b _0809E1C2
	.align 2, 0
_0809E1B0: .4byte 0x085AD004
_0809E1B4: .4byte 0x085AD00C
_0809E1B8:
	ldr r0, _0809E1F0 @ =0x085AD00C
	lsls r1, r1, #1
	adds r0, r1, r0
	ldrh r5, [r0]
	ldr r0, _0809E1F4 @ =0x085AD004
_0809E1C2:
	adds r1, r1, r0
	ldrh r4, [r1]
	ldrh r2, [r6]
	subs r1, r2, r5
	mov r0, ip
	adds r0, #0xa0
	strh r1, [r0]
	ldrh r1, [r6, #4]
	subs r0, r1, r4
	mov r3, ip
	adds r3, #0xa2
	strh r0, [r3]
	adds r2, r5, r2
	mov r0, ip
	adds r0, #0xa4
	strh r2, [r0]
	adds r1, r4, r1
	adds r0, #2
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809E1F0: .4byte 0x085AD00C
_0809E1F4: .4byte 0x085AD004

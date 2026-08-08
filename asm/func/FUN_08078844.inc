	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080788A8
	ldr r0, _0807889C @ =0x03002C00
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _080788A8
	ldr r4, _080788A0 @ =0x000001F5
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _08078872
	cmp r0, #0x10
	bne _080788A8
_08078872:
	ldr r1, _080788A4 @ =0x00000392
	adds r0, r2, r1
	ldrh r0, [r0]
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrh r1, [r1]
	ldr r3, [r3]
	subs r4, #0xa
	adds r2, r3, r4
	ldrh r2, [r2]
	subs r4, #2
	adds r3, r3, r4
	ldrb r3, [r3]
	bl FUN_0808626c
	cmp r0, #0
	beq _080788A8
	movs r0, #1
	b _080788AA
	.align 2, 0
_0807889C: .4byte 0x03002C00
_080788A0: .4byte 0x000001F5
_080788A4: .4byte 0x00000392
_080788A8:
	movs r0, #0
_080788AA:
	pop {r4}
	pop {r1}
	bx r1

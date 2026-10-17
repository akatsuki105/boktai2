	push {lr}
	ldr r0, _08086788 @ =0x03002C00
	ldr r1, [r0]
	cmp r1, #0
	beq _08086798
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _0808678C @ =0x0000040A
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086790 @ =0x000003B6
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08086798
	ldr r2, _08086794 @ =0x000001F5
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bls _08086782
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08086798
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08086798
_08086782:
	movs r0, #1
	b _0808679A
	.align 2, 0
_08086788: .4byte 0x03002C00
_0808678C: .4byte 0x0000040A
_08086790: .4byte 0x000003B6
_08086794: .4byte 0x000001F5
_08086798:
	movs r0, #0
_0808679A:
	pop {r1}
	bx r1
	.align 2, 0

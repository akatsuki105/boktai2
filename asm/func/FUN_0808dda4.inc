	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0808DDAA:
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD4 @ =0x00000C0C
	adds r0, r0, r1
	bl MainSprite_Remove
	movs r0, #0x68
	muls r0, r4, r0
	adds r0, r0, r5
	ldr r1, _0808DDD8 @ =0x00000DA4
	adds r0, r0, r1
	bl MainSprite_Remove
	adds r4, #1
	cmp r4, #3
	ble _0808DDAA
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808DDD4: .4byte 0x00000C0C
_0808DDD8: .4byte 0x00000DA4

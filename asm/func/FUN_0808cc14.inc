	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808CC7E
	ldr r0, _0808CC4C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0808CC78
	ldr r1, _0808CC50 @ =0x00000A31
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x1d
	bhi _0808CC54
	adds r0, r4, #0
	bl FUN_0808cbd8
	b _0808CC5A
	.align 2, 0
_0808CC4C: .4byte 0x030046A0
_0808CC50: .4byte 0x00000A31
_0808CC54:
	adds r0, r4, #0
	bl FUN_0808cb90
_0808CC5A:
	ldr r0, _0808CC74 @ =0x00000A31
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3b
	bls _0808CC7E
	movs r0, #0
	strb r0, [r1]
	b _0808CC7E
	.align 2, 0
_0808CC74: .4byte 0x00000A31
_0808CC78:
	adds r0, r4, #0
	bl FUN_0808cbd8
_0808CC7E:
	pop {r4}
	pop {r0}
	bx r0

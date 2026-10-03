	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0808CBCC
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl FUN_0808a420
	adds r2, r0, #0
	movs r1, #0
	ldr r0, _0808CBD4 @ =0xFFFFD000
	adds r3, r0, #0
_0808CBB2:
	adds r0, r1, #0
	adds r0, #0xa0
	orrs r0, r3
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	cmp r1, #8
	ble _0808CBB2
	movs r0, #0xa3
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808CBCC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0808CBD4: .4byte 0xFFFFD000

	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r1, #0
_0808CAD2:
	lsls r0, r1, #6
	adds r6, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0808CAFC @ =0x00003B94
	adds r0, r0, r1
	adds r4, r7, r0
	movs r5, #7
_0808CAE2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x40
	subs r5, #1
	cmp r5, #0
	bge _0808CAE2
	adds r1, r6, #0
	cmp r1, #1
	ble _0808CAD2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0808CAFC: .4byte 0x00003B94

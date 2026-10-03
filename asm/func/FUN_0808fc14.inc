	push {r4, lr}
	ldr r0, _0808FC4C @ =0x030046A0
	ldr r3, [r0]
	movs r0, #0x95
	lsls r0, r0, #2
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0xe
	bgt _0808FC5C
	ldr r1, _0808FC50 @ =0x085ACEC8
	lsls r0, r0, #2
	adds r1, r0, r1
	ldr r2, [r1]
	ldr r1, _0808FC54 @ =0x085ACF04
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r4, _0808FC58 @ =0x00000256
	adds r0, r3, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r2
	ldrb r0, [r0, #0xf]
	b _0808FC62
	.align 2, 0
_0808FC4C: .4byte 0x030046A0
_0808FC50: .4byte 0x085ACEC8
_0808FC54: .4byte 0x085ACF04
_0808FC58: .4byte 0x00000256
_0808FC5C:
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r0, #0x40
_0808FC62:
	pop {r4}
	pop {r1}
	bx r1

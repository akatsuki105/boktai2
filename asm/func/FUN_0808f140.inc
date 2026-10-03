	push {lr}
	ldr r0, _0808F158 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0808F15C @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	cmp r1, #1
	bgt _0808F160
	movs r0, #9
	b _0808F16C
	.align 2, 0
_0808F158: .4byte 0x030046A0
_0808F15C: .4byte 0x00000942
_0808F160:
	cmp r1, #9
	bgt _0808F16A
	movs r0, #0xb
	subs r0, r0, r1
	b _0808F16C
_0808F16A:
	movs r0, #2
_0808F16C:
	pop {r1}
	bx r1

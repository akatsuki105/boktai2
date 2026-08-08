	push {lr}
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	bne _0807D176
	movs r0, #1
	rsbs r0, r0, #0
	b _0807D17A
_0807D176:
	bl fetch_082316e4
_0807D17A:
	pop {r1}
	bx r1
	.align 2, 0

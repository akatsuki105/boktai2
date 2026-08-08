	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	bne _0807AFF8
	movs r0, #0
	b _0807AFFC
_0807AFF8:
	bl fetch_082316e4
_0807AFFC:
	pop {r1}
	bx r1

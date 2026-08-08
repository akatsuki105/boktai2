	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	bne _0807B012
	movs r0, #0
	b _0807B026
_0807B012:
	bl fetch_082316e4
	strh r0, [r4]
	bl fetch_082316e4
	strh r0, [r4, #2]
	bl fetch_082316e4
	strh r0, [r4, #4]
	movs r0, #1
_0807B026:
	pop {r4}
	pop {r1}
	bx r1

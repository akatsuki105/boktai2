	push {r4, lr}
	adds r2, r0, #0
	movs r1, #0xe1
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08088138
	movs r4, #0xe4
	lsls r4, r4, #2
	adds r1, r2, r4
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _08088120
	subs r0, #1
	strh r0, [r1]
	b _08088138
_08088120:
	ldr r4, _08088140 @ =0x00000392
	adds r0, r2, r4
	ldrh r0, [r0]
	strh r0, [r1]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r0, #1
	strh r0, [r1]
	ldr r1, _08088144 @ =0x00000396
	adds r0, r2, r1
	strh r3, [r0]
_08088138:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08088140: .4byte 0x00000392
_08088144: .4byte 0x00000396

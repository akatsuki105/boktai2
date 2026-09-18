	push {lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #2
	strh r0, [r1]
	ldr r0, _080A71F0 @ =0x0000033E
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x40
	bgt _080A71EA
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080A71F4 @ =0x00000341
	adds r1, r2, r0
	movs r0, #4
	strb r0, [r1]
_080A71EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A71F0: .4byte 0x0000033E
_080A71F4: .4byte 0x00000341

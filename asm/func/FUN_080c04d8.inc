	push {lr}
	ldr r0, _080C04FC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, _080C0500 @ =0x0000042E
	adds r3, r0, r1
	ldrh r0, [r3]
	cmp r0, #3
	bhi _080C050C
	ldr r1, _080C0504 @ =0x04000050
	movs r0, #0xee
	strh r0, [r1]
	ldr r2, _080C0508 @ =0x04000054
	ldrh r1, [r3]
	movs r0, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	strh r0, [r2]
	b _080C051A
	.align 2, 0
_080C04FC: .4byte 0x03002BE0
_080C0500: .4byte 0x0000042E
_080C0504: .4byte 0x04000050
_080C0508: .4byte 0x04000054
_080C050C:
	ldr r1, _080C0524 @ =0x04000050
	movs r0, #0xae
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r3]
	subs r0, #4
	strh r0, [r1]
_080C051A:
	ldr r1, _080C0528 @ =0x04000052
	movs r0, #0
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080C0524: .4byte 0x04000050
_080C0528: .4byte 0x04000052

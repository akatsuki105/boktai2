	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _0807AA56
	movs r0, #0xda
	lsls r0, r0, #2
	adds r3, r2, r0
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldr r4, _0807AA5C @ =0x0000036A
	adds r1, r2, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _0807AA56
	strh r1, [r3]
_0807AA56:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807AA5C: .4byte 0x0000036A

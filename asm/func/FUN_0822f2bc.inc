	push {r4, lr}
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r2, [r0, #0xc]
	movs r3, #0
	ldrh r0, [r0, #2]
	cmp r3, r0
	bge _0822F2E0
	adds r1, r0, #0
_0822F2CE:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0822F2D8
	adds r0, r2, #0
	b _0822F2E2
_0822F2D8:
	adds r2, #0x14
	adds r3, #1
	cmp r3, r1
	blt _0822F2CE
_0822F2E0:
	movs r0, #0
_0822F2E2:
	pop {r4}
	pop {r1}
	bx r1

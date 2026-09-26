	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bne _080A9914
	adds r0, r5, #0
	bl FUN_080a962c
	ldr r0, _080A9948 @ =0x00000285
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x24]
_080A9914:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A9942
	bl FUN_0824082c
	ldr r2, _080A994C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080A9950 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl KillEntity
_080A9942:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A9948: .4byte 0x00000285
_080A994C: .4byte 0x030044BC
_080A9950: .4byte 0x030047A4

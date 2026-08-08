	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08068304
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08068300 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _08068304
	movs r0, #1
	b _08068306
	.align 2, 0
_08068300: .4byte 0x0000036A
_08068304:
	movs r0, #0
_08068306:
	pop {r1}
	bx r1
	.align 2, 0

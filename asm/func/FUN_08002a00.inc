	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _08002A38 @ =0x00007BE3
	bl Registry_Find
	adds r2, r0, #0
	cmp r2, #0
	beq _08002A3C
	ldr r1, [r2, #0x28]
	cmp r1, #0xf
	bhi _08002A3C
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2c
	adds r0, r0, r1
	strh r4, [r0]
	ldr r1, [r2, #0x28]
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x2e
	adds r0, r0, r1
	strh r5, [r0]
	ldr r0, [r2, #0x28]
	adds r0, #1
	str r0, [r2, #0x28]
	movs r0, #0
	b _08002A40
	.align 2, 0
_08002A38: .4byte 0x00007BE3
_08002A3C:
	movs r0, #1
	rsbs r0, r0, #0
_08002A40:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

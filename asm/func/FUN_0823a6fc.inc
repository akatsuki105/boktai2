	push {lr}
	bl rfu_REQBN_softReset_and_checkID
	ldr r1, _0823A70C @ =0x00008001
	cmp r0, r1
	bne _0823A710
	movs r0, #1
	b _0823A72C
	.align 2, 0
_0823A70C: .4byte 0x00008001
_0823A710:
	ldr r0, _0823A720 @ =0x03003504
	ldr r1, [r0]
	ldr r0, _0823A724 @ =0x000001C1
	cmp r1, r0
	bhi _0823A728
	movs r0, #0
	b _0823A72C
	.align 2, 0
_0823A720: .4byte 0x03003504
_0823A724: .4byte 0x000001C1
_0823A728:
	movs r0, #1
	rsbs r0, r0, #0
_0823A72C:
	pop {r1}
	bx r1

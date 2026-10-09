	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #4
	movs r1, #0x80
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0821BD0C
	ldr r1, _0821BD04 @ =Entity8EC8_Update
	ldr r2, _0821BD08 @ =Entity8EC8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity8EC8_Init
	cmp r0, #0
	bge _0821BD0C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0821BD0E
	.align 2, 0
_0821BD04: .4byte Entity8EC8_Update
_0821BD08: .4byte Entity8EC8_Destroy
_0821BD0C:
	adds r0, r4, #0
_0821BD0E:
	pop {r4, r5}
	pop {r1}
	bx r1

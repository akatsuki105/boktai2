	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _080D8320 @ =0x00000AC4
	movs r0, #6
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080D832C
	ldr r1, _080D8324 @ =Player080d82ec_Update
	ldr r2, _080D8328 @ =Player080d82ec_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Player080d82ec_Init
	cmp r0, #0
	bge _080D832C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080D832E
	.align 2, 0
_080D8320: .4byte 0x00000AC4
_080D8324: .4byte Player080d82ec_Update
_080D8328: .4byte Player080d82ec_Destroy
_080D832C:
	adds r0, r4, #0
_080D832E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _0805B09C @ =0x00000E44
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805B0A8
	ldr r1, _0805B0A0 @ =Entity0805b068_Update
	ldr r2, _0805B0A4 @ =Entity0805b068_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity0805b068_Init
	cmp r0, #0
	bge _0805B0A8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805B0AA
	.align 2, 0
_0805B09C: .4byte 0x00000E44
_0805B0A0: .4byte Entity0805b068_Update
_0805B0A4: .4byte Entity0805b068_Destroy
_0805B0A8:
	adds r0, r4, #0
_0805B0AA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

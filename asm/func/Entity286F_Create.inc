	push {r4, lr}
	ldr r0, _08044094 @ =0x03002B50
	ldr r0, [r0]
	cmp r0, #0
	bne _080440A6
	ldr r1, _08044098 @ =0x0000043C
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080440A4
	ldr r1, _0804409C @ =Entity286F_Update
	ldr r2, _080440A0 @ =Entity286F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity286F_Init
	cmp r0, #0
	bge _080440A4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080440A6
	.align 2, 0
_08044094: .4byte 0x03002B50
_08044098: .4byte 0x0000043C
_0804409C: .4byte Entity286F_Update
_080440A0: .4byte Entity286F_Destroy
_080440A4:
	adds r0, r4, #0
_080440A6:
	pop {r4}
	pop {r1}
	bx r1

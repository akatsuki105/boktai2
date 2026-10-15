	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _080A5E00 @ =0x03002C4C
	ldr r0, [r0]
	cmp r0, #0
	bne _080A5E46
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _080A5E04
	bl VM_GetValue
	adds r5, r0, #0
	b _080A5E06
	.align 2, 0
_080A5E00: .4byte 0x03002C4C
_080A5E04:
	movs r5, #1
_080A5E06:
	movs r0, #0xbc
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A5E44
	ldr r1, _080A5E3C @ =Entity8AF6_Update
	ldr r2, _080A5E40 @ =Entity8AF6_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	adds r3, r5, #0
	bl Entity8AF6_Init
	cmp r0, #0
	bge _080A5E44
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A5E46
	.align 2, 0
_080A5E3C: .4byte Entity8AF6_Update
_080A5E40: .4byte Entity8AF6_Destroy
_080A5E44:
	adds r0, r4, #0
_080A5E46:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

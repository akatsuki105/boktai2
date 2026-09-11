	push {r4, lr}
	movs r1, #0x8c
	lsls r1, r1, #3
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013280
	ldr r1, _08013278 @ =PasswordScreen_Update
	ldr r2, _0801327C @ =PasswordScreen_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl PasswordScreen_Init
	cmp r0, #0
	bge _08013280
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013282
	.align 2, 0
_08013278: .4byte PasswordScreen_Update
_0801327C: .4byte PasswordScreen_Destroy
_08013280:
	adds r0, r4, #0
_08013282:
	pop {r4}
	pop {r1}
	bx r1

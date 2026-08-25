	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _0807F62C @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	bne _0807F63A
	movs r0, #2
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0807F638
	ldr r1, _0807F630 @ =Entity5941_Update
	ldr r2, _0807F634 @ =Entity5941_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity5941_Init
	cmp r0, #0
	bge _0807F638
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0807F63A
	.align 2, 0
_0807F62C: .4byte 0x03002BF8
_0807F630: .4byte Entity5941_Update
_0807F634: .4byte Entity5941_Destroy
_0807F638:
	adds r0, r4, #0
_0807F63A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

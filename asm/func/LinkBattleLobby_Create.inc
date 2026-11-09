	push {r4, lr}
	ldr r0, _081DC674 @ =0x030001A8
	ldr r0, [r0]
	cmp r0, #0
	bne _081DC682
	movs r1, #0xf7
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DC680
	ldr r1, _081DC678 @ =LinkBattleLobby_Update
	ldr r2, _081DC67C @ =LinkBattleLobby_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl LinkBattleLobby_Init
	cmp r0, #0
	bge _081DC680
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DC682
	.align 2, 0
_081DC674: .4byte 0x030001A8
_081DC678: .4byte LinkBattleLobby_Update
_081DC67C: .4byte LinkBattleLobby_Destroy
_081DC680:
	adds r0, r4, #0
_081DC682:
	pop {r4}
	pop {r1}
	bx r1
